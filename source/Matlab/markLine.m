function markLine(img, mark, endPoint)
%-------------------------------------------------------------
%������ʼ�˵���������Ƕ�ֵ����ͼ�е�һ����(�ݹ鷽��)
%imgAns: ��Ǻ��ͼ
%img: �����ֵ����ͼ
%mark: ���ֵ
%endPoint: ��ʼ�˵�
%-------------------------------------------------------------
global imgTree;
[width, height] = size(img);
imgTree(endPoint(1), endPoint(2)) = mark;  %���

neighbour = [-1,-1; -1,0; -1,1; 0,-1; 0,1; 1,-1; 1,0; 1,1]; %������

for k = 1:8
   p = endPoint + neighbour(k,:);
   if (p(1) > 0 && p(1) <= width) && (p(2) > 0 && p(2) <= height)
       if 1 == img(p(1), p(2)) && mark ~= imgTree(p(1), p(2))
           markLine(img, mark, p);
       end
   end
end


