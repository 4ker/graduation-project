function [header, img_data] = getImg(filename)
%-------------------------------------------------------------
%����file�������ļ����ж��ļ�ͷ��ȡͼ������
%filename: �ļ���
%img_data: ��ȡ������ͼ�����(0-255�Ҷ�ͼ)
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
    fseek(file, 4, 'bof');          %���˵�mark��
    header = fread(file, 9, 'uint32');  %��ȡ��Ϣͷ
    for i=1:size(2)
        img_data(i,1:size(1)) = fread(file, size(1), 'uchar');
    end
end
fclose(file);
%function end