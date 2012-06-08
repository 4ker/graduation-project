function img_Line = houghProcess(BW, img_Direction, houghPeaksThresh, ...
    joinLen, discardLen, originalThresh, directionThresh)
%-------------------------------------------------------------
%hough�任�Զ�ֵ��Եͼ���е�·��ȡ
%BW: �����ֵ��Եͼ
%img_Direction: �����߶ι��˵ķ���ͼ
%houghPeaksThresh: ��ȡHough������>=���ֵ*houghPeaksThresh�ĵ� (0-1)
%joinLen: �ϲ�����С��joinLen���߶�
%discardLen: �������г���С��discardLen���߶�
%originalThresh: lineFilter()�в��� (0-1)
%directionThresh: LineFilter()�в��� (0-1)
%img_Line: ����������
%-------------------------------------------------------------

%Ĭ�ϲ���
if nargin < 3 
    houghPeaksThresh = 0.4;
    joinLen = 12;
    discardLen = 100;
    originalThresh = 0.8;
    directionThresh = 0.5;
end

[width, height] = size(BW);
%ִ��Hough�任
[H,T,R]=hough(BW);
%figure,imshow(H,[],'XData',T,'YData',R,'InitialMagnification','fit');
%xlabel('\theta'),ylabel('\rho');
%axis on,axis normal,hold on;

%��Hough������Ѱ��ǰ200������Hough���������ֵhoughPeaksThresh���ķ�ֵ
%P: hough�任�ļ�ֵ��
P = houghpeaks(H,200,'threshold',ceil(houghPeaksThresh * max(H(:))));
%x=T(P(:,2));y=R(P(:,1));%���С�������ת����ʵ������
%plot(x,y,'s','color','white');%��Hough����ͼ���б����ֵλ��
%�ҳ�������ֱ��
%�ϲ�����С��joinLen���߶Σ��������г���С��discardLen��ֱ�߶�
lines=houghlines(BW,T,R,P, 'FillGap', joinLen, 'MinLength', discardLen);
img_Line = zeros(width, height);
%figure,imshow(BW),hold on
fprintf(1, '70%%\n');
for k = 1:length(lines) %���δ������ֱ�߶�
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