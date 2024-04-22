% test4

load trimcond

X = X_trim;
U = U_trim;
XCG = xcg;
XD = F16DYN(X,U,XCG);

XD_DES = XD;
U_OUT = F16DYNINV(XD,X,XCG,XD_DES);

disp([U U_OUT])

