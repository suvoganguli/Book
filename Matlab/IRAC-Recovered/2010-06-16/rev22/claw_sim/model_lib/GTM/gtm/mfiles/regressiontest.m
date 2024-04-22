function regressiontest()

delete('./docs/testdir/current/*.html');
delete('./docs/testdir/current/*.png');

for i=[1:5],
 publish(sprintf('example%d',i),...
          struct('format','html',...
                 'imageFormat','png',...
                 'outputDir','docs/testdir/current',...
                 'showCode',false));
end

fid=fopen('./docs/testdir/current/index.html','w');
fprintf(fid,'<html><head>Regression Test gtm_design</head>\n<body>\n');
fprintf(fid,sprintf('<H2> Example Run<br> Current at %s<br><br>\n',datestr(now)));
fprintf(fid,'<table><tr><td><b>Current Sim</b></td>');
fprintf(fid,'<td>&nbsp&nbsp&nbsp</td><td><b>Reference Sim</b></td></tr>\n');

for i=[1:5],
   fprintf(fid,sprintf('<tr><td><a href=example%d.html>example-%d</a></td><td></td><td><a href=../reference/example%d.html>example-%d</a></td></tr>\n',i,i,i,i));
end
fprintf(fid,'</table>\n</body>\n</html>');
fclose(fid);

web([pwd,'/docs/testdir/current/index.html']);


  

