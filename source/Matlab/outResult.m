function outResult(readAnsFile, readOrigFile, saveResFile)
%-------------------------------------------------------------
%����7
%���ݲ���6�����עԭͼ
%readAnsFile: ����Ĳ���6�����ĵ�·����ļ�
%readOrigFile: �����ԭSARͼ
%saveResFile : ��ע���SARͼ
%-------------------------------------------------------------

[head, imgAnsFile] = getImg(readAnsFile);
I = imread(readOrigFile);
fprintf(1, '20%% Done!\n');
[width, height] = size(imgAnsFile);
for i=1:width
    for j=1:height
        if 1 == imgAnsFile(i,j)
            I(i,j,1) = 0;
            I(i,j,2) = 255; %��ɫ��ע
            I(i,j,3) = 0;
        end
    end
end
fprintf(1, '80%% Done!\n');
imwrite(I, saveResFile);
fprintf(1, '100%% Done!\n');

%function end