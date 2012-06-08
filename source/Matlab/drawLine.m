function img = drawLine(image , point1, point2)
%-------------------------------------------------------------
%�ڶ�ֵͼ�����ϻ��߶�,�������Ƿ񸲸�
%image: ��ֵͼ����
%point1,point2: �߶ζ˵�
%img: �����߶εĶ�ֵͼ����
%-------------------------------------------------------------
dx = abs( point2(1) - point1(1) );
dy = abs( point2(2) - point1(2) );
steps = max(dx , dy);
xin= double(dx/steps)*sign(point2(1) - point1(1));
yin= double(dy/steps)*sign(point2(2) - point1(2));
pix_x = point1(1);
pix_y = point1(2);

for i = 1:steps
   image( round( pix_y ) ,round( pix_x ) ) = 1;
   pix_x = pix_x + xin;
   pix_y = pix_y + yin;
end
img = image;
%function end
