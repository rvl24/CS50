# View As

## Questions

9.1. An acccess token is typically a long string of nonsensical numbers and letters 
     that contain encoded information about a login session for a given application,
     including info about the logged in user. 
     
9.2. 1) A bug which allowed someone in View Mode to post a video. 2) A bug which 
     caused an access token to be generated during video uploading that contained
     more info than it should have, and 3) a bug which caused that token, when generated
     from View Mode, to be generated for the user being looked up rather than the 
     viewer. 

9.3. Since a bunch of access tokens were compromised, and access tokens are associated 
     with a specific login session, logging everyone out essentially invalidated all 
     the compromised acccess tokens. 

9.4. Session cookies just keep track of whether a user has logged in recently, and 
     they automatically go away when you stop the application by closing the browser. 
     Access tokens contain more user information and can be used to allow other 
     applications to obtain and use user information. They hang around even after a
     user closes an application, assuming they don't log out. 

## Debrief

a. TODO

b. TODO minutes
