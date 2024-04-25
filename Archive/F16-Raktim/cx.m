function cx = cx(alpha, el)
    a = [-.099, -.081, -.081, -.063, -.025, .044, .097, .113, .145, .167, .174, .166
         -.048, -.038, -.040, -.021, .016, .083, .127, .137, .162, .177, .179, .167 
         -.022, -.020, -.021, -.004, .032, .094, .128, .130, .154, .161, .155, .138
         -.040, -.038, -.039, -.025, .006, .062, .087, .085, .100, .110, .104, .091, 
         -.083, -.073, -.076, -.072, -.046, .012, .024, .025, .043, .053, .047, .040];
    s = 0.2 * alpha;
    k = fix(s);
    if k <= -2 + 2
        k = -1 + 2;
    end
    if k >= 9 + 2
        k = 8 + 2;
    end
    da = s - double(k);
    l = k + fix(sign_(1.1, da));
    s = el / 12.0;
    m = fix(s);
    if m <= -2 + 2
        m = -1 + 2;
    end
    if m >= 2 + 2
        m = 1 + 2;
    end
    de = s - double(m);
    n = m; fix(sign_(1.1, de));
    t = a(k);
    u = a(k, n);
    v = t + abs(da) * (a(l, m) - t);
    w = u + abs(da) * (a(l, n) - u);
    cx = v + (w - v) * abs(de);
end

function out = sign_(x,y)

if y >= 0
    out = abs(x);
elseif y < 0
    out = -abs(x);
end

end

% function cy = cy(beta, ail, rdr)
%     cy = -.02 * beta + .021 * (ail / 20.0) + .086 * (rdr / 30.0);
% end
% 
% function cz = cz(alpha, beta, el)
%     a = [.770, .241, -.100, -.416, -.731, -1.053, -1.366, -1.646, -1.917, -2.120, -2.248, -2.229];
%     s = 0.2 * alpha;
%     k = fix(s);
%     if k <= -2
%         k = -1;
%     end
%     if k >= 9
%         k = 8;
%     end
%     da = s - double(k);
%     l = k + fix(sign(1.1, da));
%     s = a(k) + abs(da) * (a(l) - a(k));
%     cz = s * (1 - (beta / 57.3) ^ 2) - .19 * (el / 25.0);
% end
% 
