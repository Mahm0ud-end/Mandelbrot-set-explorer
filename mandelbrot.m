function mandelbrot(N, MaxIteration, c_x, c_y, half_range,ax)
    c_y= -1*c_y;
    x1 = c_x - half_range;   x2 = c_x + half_range;
    y1 = c_y - half_range; y2 = c_y + half_range;
    X=linspace(x1, x2, N);
    Y=linspace(y1, y2, N);
    [x,y] = meshgrid(X, Y);
    
    c = x + 1i * y;
    z = zeros(size(c));
    k = zeros(size(c));
    op=logical(ones(size(c)));
    for ii = 1:MaxIteration
        z(op)   = z(op).^2 + c(op);
        k(abs(z) > 2 & k == 0) = MaxIteration - ii;
        op=(k==0);
%         if ~any(op,'all')
%             break;
%         end
    end
%     k(abs(z) > 2 & k == 0) = 1;
    
    if nargin==5
        imagesc(X,Y,k);
        colormap hot
        axis square
    elseif nargin==6
%         axes(ax);
        imagesc(ax,X,Y,k);
        axis(ax,'square');
        colormap(ax,'hot');
        xlim(ax,[X(1) X(end)]);
        ylim(ax,[Y(1) Y(end)]);
    end
end

% F=@(c_x,c_y,g)(mandelbrot(200,50, c_x, c_y, g))