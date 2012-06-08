function res = lineFilter(BW, thresh1, img_Direct, ...
    thresh2, point1, point2)
%-------------------------------------------------------------
%基于线段与原二值图点重合度和线段方向符合度进行线段过滤
%BW: 原二值图矩阵
%thresh1: 点重合百分比,取值0到1
%img_Direct: 原方向图,由ratioDetector()产生
%thresh2: 方向符合百分比,取值0到1
%point1,point2: 线段端点
%res: 判断结果(0或1)
%-------------------------------------------------------------

%计算线段方向
%垂直| 1
%水平- 2
%右倾\ 3
%左倾/ 4

direct = 0;  %线段方向
angle = atand((point2(2) - point1(2))/(point2(1) - point1(1)));
if angle >= 90-22.5 && angle <= -90+22.5
    direct = 2;
elseif -22.5 <= angle && angle <= 22.5
    direct = 1;
elseif 45-22.5 <= angle && angle <= 45+22.5 
    direct = 3;
elseif  angle <= -45-22.5 && angle >= -45+22.5
    direct = 4;
end

count1 = 0;  %点重合计数器
count2 = 0;  %方向符合计数器
dx = abs( point2(1) - point1(1) );
dy = abs( point2(2) - point1(2) );
steps = max(dx , dy);
xin= double(dx/steps)*sign(point2(1) - point1(1));
yin= double(dy/steps)*sign(point2(2) - point1(2));
pix_x = point1(1);
pix_y = point1(2);

for i = 1:steps
   count1 = count1 + BW( round( pix_y ) ,round( pix_x ) );
   %方向符合计数考虑4邻域
   if direct == img_Direct(round( pix_y )+1 ,round( pix_x )) || ...
       direct == img_Direct(round( pix_y ) ,round( pix_x )+1) || ...
       direct == img_Direct(round( pix_y )-1 ,round( pix_x )) || ...
       direct == img_Direct(round( pix_y ) ,round( pix_x )-1)
       count2 = count2 + 1;
   end
   pix_x = pix_x + xin;
   pix_y = pix_y + yin;
end

%点重合度结果
if count1 > (steps * thresh1)
    res1 = 1;
else
    res1 = 0;
end
%方向符合度结果
if count2 > (steps * thresh2)
    res2 = 1;
else
    res2 = 0;
end
%最终结果
res = res1 * res2;

%function end
