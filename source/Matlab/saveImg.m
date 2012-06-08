function saveImg(filename, img_data, mark, header)
%-------------------------------------------------------------
%保存图像矩阵数据到文件
%filename: 要保存的文件名
%img_data: 图像矩阵(0-255灰度图)
%mark: 文件标示
%header: 信息头
%-------------------------------------------------------------

[width, height] = size(img_data);
fname = filename;
file = fopen(fname, 'wb+');
if -1 == file
    fprintf(2, 'Error save file!\n');
    return;
end
width = uint32(width);
height = uint32(height);
fwrite(file, mark, 'char');
if isempty(header)
    fwrite(file, height, 'uint32');
    fwrite(file, width, 'uint32'); 
else 
    fwrite(file, header, 'uint32');
end
for i = 1:width
        fwrite(file, img_data(i,:), 'uchar');
end
fclose(file);
%function end