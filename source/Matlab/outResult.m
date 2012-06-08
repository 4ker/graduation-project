function outResult(readAnsFile, readOrigFile, saveResFile)
%-------------------------------------------------------------
%步骤7
%根据步骤6结果标注原图
%readAnsFile: 读入的步骤6产生的道路结果文件
%readOrigFile: 读入的原SAR图
%saveResFile : 标注后的SAR图
%-------------------------------------------------------------

[head, imgAnsFile] = getImg(readAnsFile);
I = imread(readOrigFile);
fprintf(1, '20%% Done!\n');
[width, height] = size(imgAnsFile);
for i=1:width
    for j=1:height
        if 1 == imgAnsFile(i,j)
            I(i,j,1) = 0;
            I(i,j,2) = 255; %绿色标注
            I(i,j,3) = 0;
        end
    end
end
fprintf(1, '80%% Done!\n');
imwrite(I, saveResFile);
fprintf(1, '100%% Done!\n');

%function end