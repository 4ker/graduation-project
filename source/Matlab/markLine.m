function markLine(img, mark, endPoint)
%-------------------------------------------------------------
%根据起始端点搜索并标记二值线条图中的一棵树(递归方法)
%imgAns: 标记后的图
%img: 读入二值线条图
%mark: 标记值
%endPoint: 起始端点
%-------------------------------------------------------------
global imgTree;
[width, height] = size(img);
imgTree(endPoint(1), endPoint(2)) = mark;  %标记

neighbour = [-1,-1; -1,0; -1,1; 0,-1; 0,1; 1,-1; 1,0; 1,1]; %八邻域

for k = 1:8
   p = endPoint + neighbour(k,:);
   if (p(1) > 0 && p(1) <= width) && (p(2) > 0 && p(2) <= height)
       if 1 == img(p(1), p(2)) && mark ~= imgTree(p(1), p(2))
           markLine(img, mark, p);
       end
   end
end


