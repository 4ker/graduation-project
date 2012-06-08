function saveImg(filename, img_data, mark, header)
%-------------------------------------------------------------
%����ͼ��������ݵ��ļ�
%filename: Ҫ������ļ���
%img_data: ͼ�����(0-255�Ҷ�ͼ)
%mark: �ļ���ʾ
%header: ��Ϣͷ
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