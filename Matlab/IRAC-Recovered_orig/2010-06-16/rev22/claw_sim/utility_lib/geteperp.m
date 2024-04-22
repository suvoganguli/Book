function eperp = geteperp(e)

e0 = e(1);
e1 = e(2);
e2 = e(3);
e3 = e(4);

eperp = [
    -e1 -e2 -e3
     e0 -e3  e2
     e3  e0 -e1
    -e2  e1  e0
    ];
