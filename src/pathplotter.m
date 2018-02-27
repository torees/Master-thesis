function pathplotter(eta, tsamp, dec,t,color)% tstart, tstop track, WP)
x=eta(:,1);
y=eta(:,2);
psi_g=eta(:,3);
%PATHPLOTTER draws the path of the ship MS Fartoystyring used in TTK4190 
%Guidance and Control Assignment 3, Tasks 2.3 to 2.7, inclusive.
%
%PATHPLOTTER outputs a single xy-plot of the MS Fartoystyring's trajectory 
%and, depending upon the input, either waypoints and path or the trajectory
%of the target. The MS Fartoystyring is yellow and the target green. MS
%Fartoystyring's trajectory is blue, and the waypoints/target trajectory
%red.
%
%x      is the ship's north position (in NED). x is a vector in R^T, T is 
%          number of samples
%y      is the ship's east position (in NED). y is a vector in R^T 
%psi    is the ship's yaw angle (in NED). psi is a vector in R^T 
%tsamp  is the sampling time
%dec>=1 is how much of the data should be used in the plot. dec should 
%          be a natural number. E.g. dec=2 reduces number of data points by
%          a factor of 2. Too low value of dec makes the plot illegible
%tstart is simulation start time
%tstop  is simulation stop time
%track  is a boolean value indicating whether or not the ship is following 
%          waypoints (Tasks 2.3-2.6) (track=0) or tracking a target (Task
%          2.7) (track=1).
%
%Input must be sampled with a fixed time step.
%
%Author   : Christian Holden
%Date     : 2008-02-22
%Revisions: 2009-01-15 C. Holden. Updated for new semester. 
%           2010-02-22 C. Holden. Updated for new semester.
%           2010-03-02 C. Holden. Minor bug fix
%
%You are free to modify the code as necessary.
%
%Bugs should be reported to the TA.
%close all



plot(y,x,'-.r','LineWidth',1.5)
L_g=200/6;
tnow=t(1);

for now=1:dec:length(x)
    
    
    %MS Fartoystyring
    R_g = [cos(psi_g(now)) -sin(psi_g(now)); sin(psi_g(now)) cos(psi_g(now))];
    boat = R_g/40*[6*L_g/9 5*L_g/9 3*L_g/9 -5*L_g/9 -5*L_g/9 3*L_g/9 5*L_g/9 6*L_g/9;
                0 1*L_g/9 2*L_g/9 2*L_g/9 -2*L_g/9 -2*L_g/9 -1*L_g/9 0];

    plot(y(now)+boat(2,:),x(now)+boat(1,:),color,'LineWidth',1.5)
    
   
    
    tnow=tnow+tsamp*dec;
end


end