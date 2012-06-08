function houghTrans(readEdgeFile, readDireFile, saveLineFile, ...
    filterWinSize, filterThresh, ...
    houghPeaksThresh, joinLen, discardLen, ...
    originalThresh, directionThresh)
%-------------------------------------------------------------
%����4 hough�任
%readEdgeFile: ����ı�Եͼ
%readDireFile: ����ķ���ͼ
%saveLineFile: ������߶�ͼ
%filterWinSize, filterThresh: ���ݸ�imgBlockFilter()
%houghPeaksThresh, joinLen, discardLen, originalThresh,
%directionThresh: ���ݸ�houghProcess()
%-------------------------------------------------------------

if nargin < 4 
    filterWinSize = 5;
    filterThresh = 20;
    houghPeaksThresh = 0.4;
    joinLen = 12;
    discardLen = 100;
    originalThresh = 0.8;
    directionThresh = 0.5;
end

if ischar(filterWinSize)
    filterWinSize = str2num(filterWinSize);
end
if ischar(filterThresh)
    filterThresh = str2num(filterThresh);
end
if ischar(houghPeaksThresh)
    houghPeaksThresh = str2num(houghPeaksThresh);
end
if ischar(joinLen)
    joinLen = str2num(joinLen);
end
if ischar(discardLen)
    discardLen = str2num(discardLen);
end
if ischar(originalThresh)
    originalThresh = str2num(originalThresh);
end
if ischar(directionThresh)
    directionThresh = str2num(directionThresh);
end

[header_edge, img_edge] = getImg(readEdgeFile);
[header_dire, img_dire] = getImg(readDireFile);
img_edge = imgBlockFilter(img_edge, filterWinSize, filterThresh);
fprintf(1, '60%%\n');
img_Line = houghProcess(img_edge, img_dire, ...
    houghPeaksThresh, joinLen, discardLen, ...
    originalThresh, directionThresh);
saveImg(saveLineFile, img_Line, 'ImgL', header_edge);
fprintf(1, '100%% Done!\n');
%function end