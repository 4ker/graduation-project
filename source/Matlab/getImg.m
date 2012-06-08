function [header, img_data] = getImg(filename)
%-------------------------------------------------------------
%读入file二进制文件，判断文件头读取图像数据
%filename: 文件名
%img_data: 读取出来的图像矩阵(0-255灰度图)
%-------------------------------------------------------------
fname = filename;
file = fopen(fname, 'rb');
if -1 == file
    fprintf(2, 'Error open file!\n');
    return;
end
mark = fread(file, 4, 'char=>char');
if strcmp(mark', 'ImgB') || strcmp(mark', 'ImgA')
    size = fread(file, 2, 'uint32');
    header = '';
    img_data = zeros(size(2), size(1));
    for i=1:size(2)
        img_data(i,1:size(1)) = fread(file, size(1), 'uchar');  
    end
elseif strcmp(mark', 'ImgC') || strcmp(mark', 'ImgE') || ...
       strcmp(mark', 'ImgH') || strcmp(mark', 'ImgS') || ...
       strcmp(mark', 'ImgD') || strcmp(mark', 'ImgL')
    fseek(file, 4, 'cof');
    size = fread(file, 2, 'uint32');
    img_data = zeros(size(2), size(1)); 
    fseek(file, 4, 'bof');          %回退到mark后
    header = fread(file, 9, 'uint32');  %提取信息头
    for i=1:size(2)
        img_data(i,1:size(1)) = fread(file, size(1), 'uchar');
    end
end
fclose(file);
%function end