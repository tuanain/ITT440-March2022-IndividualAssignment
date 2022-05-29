/*

	Server
	Individual Assignment: Tuan Nurulain Nabilah
	Protocol: SMTP

*/

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

    	while(recvsize < size) {
        FD_ZERO(&fd_s);
        FD_SET(socket,&fd_s);

        bufferfd = select(FD_SETSIZE,&fd_s,NULL,NULL,&timeout);

        if (bufferfd < 0)
            printf("Error occured due to bad file descriptor set.\n");

        if (bufferfd == 0)
            printf("Error occured due to buffer read timeout expired.\n");
        if(bufferfd > 0)
        {
            do{
                readsize = read(socket, img_array, 10240);
            }while(readsize < 0);

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

while(strcmp(buff,"QUIT") != 0);

    printf("RECEIVED : %s",buff);
    bzero(buff,10240);
    strcpy(buff,"221 Bye");
    printf("SENT : %s\n\n",buff);
    n = write(newsockfd,buff,strlen(buff));
    if (n<0) {  perror("Error occured while writing to socket!"); }
    printf("\nConnection closed successfully with the client!\n\n");

    return 0;
}
