function img_Line = houghProcess(BW, img_Direction, houghPeaksThresh, ...
    joinLen, discardLen, originalThresh, directionThresh)
%-------------------------------------------------------------
%hough变换对二值边缘图进行道路提取
%BW: 输入二值边缘图
%img_Direction: 用于线段过滤的方向图
%houghPeaksThresh: 提取Hough矩阵中>=最大值*houghPeaksThresh的点 (0-1)
%joinLen: 合并距离小于joinLen的线段
%discardLen: 丢弃所有长度小于discardLen的线段
%originalThresh: lineFilter()中参数 (0-1)
%directionThresh: LineFilter()中参数 (0-1)
%img_Line: 处理结果矩阵
%-------------------------------------------------------------

%默认参数
if nargin < 3 
    houghPeaksThresh = 0.4;
    joinLen = 12;
    discardLen = 100;
    originalThresh = 0.8;
    directionThresh = 0.5;
end

[width, height] = size(BW);
%执行Hough变换
[H,T,R]=hough(BW);
%figure,imshow(H,[],'XData',T,'YData',R,'InitialMagnification','fit');
%xlabel('\theta'),ylabel('\rho');
%axis on,axis normal,hold on;

%在Hough矩阵中寻找前200个大于Hough矩阵中最大值houghPeaksThresh倍的峰值
%P: hough变换的极值点
P = houghpeaks(H,200,'threshold',ceil(houghPeaksThresh * max(H(:))));
%x=T(P(:,2));y=R(P(:,1));%由行、列索引转换成实际坐标
%plot(x,y,'s','color','white');%在Hough矩阵图像中标出峰值位置
%找出并绘制直线
%合并距离小于joinLen的线段，丢弃所有长度小于discardLen的直线段
lines=houghlines(BW,T,R,P, 'FillGap', joinLen, 'MinLength', discardLen);
img_Line = zeros(width, height);
%figure,imshow(BW),hold on
fprintf(1, '70%%\n');
for k = 1:length(lines) %依次处理各条直线段
    xy=[lines(k).point1; lines(k).point2];
    if lineFilter(BW, originalThresh, img_Direction, directionThresh, ...
            xy(1,:), xy(2,:))
        img_Line = drawLine(img_Line, xy(1,:), xy(2,:));
        %plot(xy(:,1),xy(:,2),'-','LineWidth',2,'Color','green');  
    end 
    fprintf(1, '%d%%\n', int32(k/length(lines)*30 + 70));
end
%figure, imshow(img_Line);
%function end