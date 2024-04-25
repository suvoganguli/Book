% print screen or pause to look at it
% depending upon option

if (printoption == 1) 
 drawnow;
 disp('sent to printer');
 print;
 pause(1);
elseif (printoption == 2)
  disp('Paused.'); pause; disp('Not Paused.');
end;
