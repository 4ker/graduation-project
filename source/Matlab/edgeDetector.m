function edgeDetector(readImgFile, saveEdgeFile, saveDireFile, ...
    winSize, thresh)
%-------------------------------------------------------------
%步骤3:边缘提取
%readImgFile: 读入图片名
%saveEdgeFile: 保存边缘图像名
%saveDireFile: 保存方向图像名
%winSize, thresh: 传递给ratioDetector()
%-------------------------------------------------------------
if nargin < 5
    thresh = 0.3;
end
if nargin < 4
    winSize = 5;
end

if ischar(winSize)
    winSize = str2num(winSize);
end

if ischar(thresh)
    thresh = str2num(thresh);
end


[header, img_data] = getImg(readImgFile);
[img_edge, img_Direction] = ratioDetector(img_data, winSize, thresh);
saveImg(saveEdgeFile, img_edge, 'ImgE', header);
fprintf(1,'98%%\n');
saveImg(saveDireFile, img_Direction, 'ImgD', header);
fprintf(1,'100%% Done!\n');
%function end
