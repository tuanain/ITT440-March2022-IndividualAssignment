/*

	Server
	Individual Assignment: Tuan Nurulain Nabilah
	Protocol: SMTP

*/
 #define domain "server,smtp.com"

 int recive_image(int socket)
 {

	int size;
	char image_array[];
	FILE *fpimage;
	int recvsize;
	int size;
	int readsize;
	int writesize;
	int packetindex;
	int status;

	do
	{
		status= read(socket, &size, sizeof(int));
	}
	while(status<0)

		printf("RECEIVED :\nPacket received");
		printf(" \n");
		char buffer[]="success!";
	do
	{
		status=write(socket, &buffer);
	}
	while(status<0);

		printf("Reply is successful\n");
		print(" \n");

		fpimage=fopen("received.jpeg", "w");

	if(fpimage==null)
	{
		printf("error occured");
		return -1;
	}

		struct timeval timeout = {10,0};

    		fd_set fd_s;
    		int bufferfd;

    	while(recvsize < size) 
	{
        	FD_ZERO(&fd_s);
        	FD_SET(socket,&fd_s);

        	bufferfd = select(FD_SETSIZE,&fd_s,NULL,NULL,&timeout);

        if (bufferfd < 0)
            	printf("Error occured due to bad file descriptor set.\n");

        if (bufferfd == 0)
            	printf("Error occured due to buffer read timeout expired.\n");
        if(bufferfd > 0)
        {
        do
	{
                readsize = read(socket, img_array, 10240);
        }
	while(readsize < 0);

            	writesize = fwrite(img_array,1,readsize, fpimage);
            	printf("Image size written : %i\n",writesize);

        if(readsize!=writesize)
        {
                printf("Error occured while reading!\n");
        }

		recvsize += readsize;
            	packetindex++;
            	printf("Total Received Image size : %i\n",recvsize);
            	printf(" \n");
	}
    }
}

 int main(int argc, char *argv[])
 {
    	int sockfd, newsockfd, n, portno, clilen;
    	struct sockaddr_in serv_addr, cli_addr;
    	char servers[2][100] = {"smtp.gmail.com","smtp.yahoo.com"};
    	char buff[10240];
	//used for buffer the incoming data from client
    	char command[50];
	//used to read command RECEIVED from client

    	sockfd = socket(AF_INET, SOCK_STREAM,0);

	if(sockfd < 0)
    	{
        	perror("\nError occured while creating the socket!\n");
    	}

    		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = atoi(argv[1]);
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);
    	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("\nSocket binding failed!\n");
	}

    		listen(sockfd,5);
    		clilen = sizeof(cli_addr);
    		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    	if (newsockfd < 0)
    	{
    		perror("\nError occured while accepting on socket!\n");
    	}

	while(strcmp(buff,"QUIT") != 0);

		printf("RECEIVED : %s",buff);
    		bzero(buff,10240);
    		strcpy(buff,"221 Bye");
    		printf("SENT : %s\n\n",buff);
    		n = write(newsockfd,buff,strlen(buff));
    	if (n<0)
	{
		perror("Error occured while writing to socket!"); 
	}

		printf("\nConnection closed successfully!\n\n");
		return 0;
}
