function res = lineFilter(BW, thresh1, img_Direct, ...
    thresh2, point1, point2)
%-------------------------------------------------------------
%�����߶���ԭ��ֵͼ���غ϶Ⱥ��߶η�����϶Ƚ����߶ι���
%BW: ԭ��ֵͼ����
%thresh1: ���غϰٷֱ�,ȡֵ0��1
%img_Direct: ԭ����ͼ,��ratioDetector()����
%thresh2: ������ϰٷֱ�,ȡֵ0��1
%point1,point2: �߶ζ˵�
%res: �жϽ��(0��1)
%-------------------------------------------------------------

%�����߶η���
%��ֱ| 1
%ˮƽ- 2
%����\ 3
%����/ 4

direct = 0;  %�߶η���
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

count1 = 0;  %���غϼ�����
count2 = 0;  %������ϼ�����
dx = abs( point2(1) - point1(1) );
dy = abs( point2(2) - point1(2) );
steps = max(dx , dy);
xin= double(dx/steps)*sign(point2(1) - point1(1));
yin= double(dy/steps)*sign(point2(2) - point1(2));
pix_x = point1(1);
pix_y = point1(2);

for i = 1:steps
   count1 = count1 + BW( round( pix_y ) ,round( pix_x ) );
   %������ϼ�������4����
   if direct == img_Direct(round( pix_y )+1 ,round( pix_x )) || ...
       direct == img_Direct(round( pix_y ) ,round( pix_x )+1) || ...
       direct == img_Direct(round( pix_y )-1 ,round( pix_x )) || ...
       direct == img_Direct(round( pix_y ) ,round( pix_x )-1)
       count2 = count2 + 1;
   end
   pix_x = pix_x + xin;
   pix_y = pix_y + yin;
end

%���غ϶Ƚ��
if count1 > (steps * thresh1)
    res1 = 1;
else
    res1 = 0;
end
%������϶Ƚ��
if count2 > (steps * thresh2)
    res2 = 1;
else
    res2 = 0;
end
%���ս��
res = res1 * res2;

%function end
