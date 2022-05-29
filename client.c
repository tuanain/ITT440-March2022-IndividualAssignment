 /* 
	Individual Assignment: Tuan Nurulain Nabilah
	Protocol: SMTP

*/

 #include<string.h>
 #include<sys/socket.h>


 #define domain "server.smtp.com"

	char mail_from[100];
	char mail_to[100];

void send_image(int socket)
{
    	FILE *fpimage;
	int size;
	int readsize;
	int status;
	int packet_index = 1;
	char send_buffer[10239];
	char read_buffer[256];
	char f_name[100];

    	printf("\nEnter Image Path/Image file name : ");
    	scanf("%s",f_name);
    	fpimage = fopen(f_name, "r");
	printf("\nCLIENT: \nGetting Image Size...\n");

	if(fpimage == NULL)
	{
		printf("Error occured while opening Image File!\n");
	}

	fseek(fpimage, 0, SEEK_END);
	size = ftell(fpimage);
	fseek(fpimage, 0, SEEK_SET);
	printf("Total Image size: %i\n",size);
	printf("Sending Image Size\n");
	write(socket, (void *)&size, sizeof(int));
	printf("Sending Image as a byte array...");

	do
	{
		status=read(socket, &read_buffer, 255);
	}
	while(status < 0);

	//printf("Data successfully received in socket!\n");
	//printf("Socket Data: %s\n", read_buffer);

	while(!feof(fpimage))
	{
        	readsize = fread(send_buffer, 1, sizeof(send_buffer)-1, fpimage);
	do
	{
		status = write(socket, send_buffer, readsize);
	}
	while(status<0);
		printf(" \n");
		printf(" \n");
        	packet_index++;
		bzero(send_buffer, sizeof(send_buffer));
	}
}

 int main(int argc, char *argv[])
 {
    int socket_id,n;
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char cname[256];
    char buff[10240];
