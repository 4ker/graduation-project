function [img_edge, img_Direction] = ratioDetector(img_data, ...
    winSize, thresh)
%-------------------------------------------------------------
%Ratio算子边缘检测
%img_data: 输入图像矩阵(0-255灰度图),
%winSize:  检测窗口大小,默认5
%thresh:   分割阈值(r < thresh 则认定该点属于边缘点)，默认0.3
%img_edge: 边缘提取后的二值图矩阵
%img_Direction: 对应img_edge的方向值"垂直":1 "水平":2 "右倾\":3 "左倾/":4
%-------------------------------------------------------------
if nargin < 3 
    thresh = 0.3; 
end
if nargin < 2 
    winSize = 5;
end

radius = floor(winSize/2); %窗口半径
img_data = double(img_data); %转成double便于后面求和计算
[width, height] = size(img_data);
img_edge = zeros(width, height);
img_Direction = zeros(width, height);

for i = radius+1 : width-radius
    for j = radius+1 : height-radius
        %垂直方向
        u1 = sum(sum(img_data(i-radius:i-1,j-radius:j+radius),1),2);
        u2 = sum(sum(img_data(i+1:i+radius,j-radius:j+radius),1),2);
        r1 = double(min(u1,u2))/max(u1,u2);
        %水平方向
        u1 = sum(sum(img_data(i-radius:i+radius,j-radius:j-1),1),2);
        u2 = sum(sum(img_data(i-radius:i+radius,j+1:j+radius),1),2);
        r2 = double(min(u1,u2))/max(u1,u2);
        %右倾45度"\"
        u1 = 0;
        u2 = 0;
        for m = 0 : winSize-1
            for n = 0 : winSize-1
                if m > n
                    u1 = u1 + img_data(i-radius+m, j-radius+n);
                elseif m < n
                    u2 = u2 + img_data(i-radius+m, j-radius+n);
                end
            end
        end
        r3 = double(min(u1,u2))/max(u1,u2);
        %左倾45度"/"
        u1 = 0;
        u2 = 0;
        for m = 0 : winSize-1
            for n = 0 : winSize-1
                if m > (winSize-1-n)
                    u1 = u1 + img_data(i-radius+m, j-radius+n);
                elseif m < (winSize-1-n)
                    u2 = u2 + img_data(i-radius+m, j-radius+n);
                end
            end
        end
        r4 = double(min(u1,u2))/max(u1,u2);
        
        %4个方向取最小值
        [r index] = min([r1,r2,r3,r4]);
        if r < thresh
            img_Direction(i, j) = index;
            img_edge(i, j) = 1;     
        end
    end
    fprintf(1, '%d%%\n', int32(i/(width-radius)*96));
end
%fucntion end