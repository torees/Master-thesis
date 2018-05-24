function pathtrackplotter_mclab_ref(eta, tsamp, dec,color1,color2)


st = [5 -1 0]';
eta_plot = [st eta'];
eta_plot = eta_plot';

x = eta_plot(:,1);
y = eta_plot(:,2);
psi = eta_plot(:,3);

p=[5 -1 0];
z = [7 -1 0];
plot(y,x,color2,'LineWidth',1.5)

L=200/6;
tnow=0;

for now=1:dec:length(x)
   
    R = [cos(psi(now)) -sin(psi(now)); sin(psi(now)) cos(psi(now))];
    boat = R/50*[6*L/9 5*L/9 3*L/9 -5*L/9 -5*L/9 3*L/9 5*L/9 6*L/9;
                0 1*L/9 2*L/9 2*L/9 -2*L/9 -2*L/9 -1*L/9 0];

    plot(y(now),x(now),color1,'LineWidth',1.5)
    
    tnow=tnow+tsamp*dec;

end
end