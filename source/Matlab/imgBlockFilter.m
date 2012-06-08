function img_ans = imgBlockFilter(image, winSize, thresh)
%-------------------------------------------------------------
%根据二值图区域块内点("1")的数目进行填充或清除操作
%image: 输入二值图矩阵
%winSize: 区域块尺寸
%thresh: 判断阈值
%img_ans: 处理后的二值图矩阵
%-------------------------------------------------------------
[width, height] = size(image);
img_ans = image;
radius = floor(winSize/2);
for i = radius+1 : width-radius
    for j = radius+1 : height-radius
        count = sum(sum(image(i-radius:i+radius,j-radius:j+radius),1),2);
        if count >= winSize*winSize-thresh
            img_ans(i,j) = 1; %填充
        elseif count < thresh
            img_ans(i,j) = 0; %清除
        end
    end
    fprintf(1, '%d%%\n', int32(i/(width-radius)*60));
end
%function end