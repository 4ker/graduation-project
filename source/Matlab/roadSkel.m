function roadSkel(readLineFile, saveSkelFile, radius, spurLen, treeFilterT)
%-------------------------------------------------------------
%步骤5
%将hough检测出来的线段图进行处理得到最终道路结果
%readLineFile: 读入二值线段图
%saveSkelFile: 保存最终结果图
%radius : 用于膨胀处理的结构元素(disk)的半径, 默认5
%spurLen: 要去除的毛刺的最大长度， 默认10
%treeFilterT: 子连通图过滤长度阈值，默认500
%-------------------------------------------------------------
if nargin < 5
    radius = 5;
end
if nargin < 4
    spurLen = 10;
end
if nargin < 3
    treeFilterT = 500;
end

if ischar(radius)
    radius = str2num(radius);
end
if ischar(spurLen)
    spurLen = str2num(spurLen);
end
if ischar(treeFilterT)
    treeFilterT = str2num(treeFilterT);
end

[header, img_Line] = getImg(readLineFile);
se = strel('disk',radius);
imdilateBW = imdilate(img_Line,se); %膨胀
fprintf(1, '20%% Done!\n');
skelBW = bwmorph(imdilateBW,'skel',Inf); %骨架化
spurBW = bwmorph(skelBW,'spur',spurLen);  %去除毛刺
fprintf(1, '50%% Done!\n');
treeFilterBW = treeFilter(spurBW, treeFilterT);
saveImg(saveSkelFile, treeFilterBW, 'ImgS', header);
fprintf(1, '100%% Done!\n');
%function end



