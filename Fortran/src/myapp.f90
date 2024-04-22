! program name
!  implicit none
  
!  print *, "Hello World from Fortran"
!  stop
! end program name

program CALC_CX
  implicit none

!  integer,save,dimension(3,5) :: gg
!  data gg(1,:) /  1,  2,  3,  4,  5 /  
!  data gg(2,:) / 10, 20, 30, 40, 50 /  
!  data gg(3,:) / 11, 22, 33, 44, 55 /  

 ! print *, gg
  real,save,dimension(5,12) :: A
  
data A(1,:) / -.099, -.081, -.081, -.063, -.025, .044, .097, .113,  .145,  .167,  .174, .166 /
data A(2,:) / -.048, -.038, -.040, -.021,  .016, .083, .127, .137,  .162,  .177,  .179, .167 /
data A(3,:) / -.022, -.020, -.021, -.004,  .032, .094, .128, .130,  .154,  .161,  .155, .138 /
data A(4,:) / -.040, -.038, -.039, -.025,  .006, .062, .087, .085,  .100,  .110,  .104, .091/
data A(5,:) / -.083, -.073, -.076, -.072, -.046, .012, .024, .025,  .043,  .053,  .047, .040/

real :: ALPHA, S, DA, EL, DE, T, U, V, W, CX
integer :: K, L, M, N

ALPHA = 0
EL = 0

S= 0.2 * ALPHA
K= INT(S)
IF(K .LE. -2 + 2) K= -1 + 2
IF(K .GE. 9 + 2) K= 8 + 2
DA= S - FLOAT(K)
L = K + INT( SIGN(1.1,DA) )
S= EL/12.0
M= INT(S)
IF(M .LE. -2 + 2) M= -1 + 2
IF(M .GE. 2 + 2) M= 1 + 2
DE= S - FLOAT(M)
N= M + INT( SIGN(1.1,DE) )

print *, K, L, M, N
print *, A(1,1)

T= A(K,M)
U= A(K,N)
V= T + ABS(DA) * (A(L,M) - T)
W= U + ABS(DA) * (A(L,N) - U)

CX= V + (W-V) * ABS(DE)

print *, CX

end program CALC_CX

