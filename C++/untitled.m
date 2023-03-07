% u=axes(figure);
tic
[k, X, Y]=mandelbrot_mex(300, 100, 0, 0.5, 0.3);
toc
tic
[k, X, Y]=mandelbrot(300, 100, 0, 0.5, 0.3);
toc

%  imagesc(X,Y,k);
%         colormap hot
%          axis square
% c=colormap();
% imshow(c)
% imagesc(X,Y,flipud(k))