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

	do
	{
		status= read(socket, &size, sizeof(int));
	}
	while(status<0)
	{
		printf("RECEIVED :\nPacket received");

		char buffer[]="success!";

	}
	do 
	{
		status=write(socket, &buffer);
	}	while(status<0);
		printf("Reply is successful\n");
		print(" \n");
	if(fpimage==null)
	{
		printf("error occured");
		return;
	}

}

	int parseARGS(char **args, char *line)
	{
		int tmp = 0;
		args[tmp] = strtok(line, ":");
		while ((args[++tmp] = strtok)NULL, ":")) != NULL);
		return tmp -1;
	}
	int count1=1, count2=1, percent;
	char *header[4096];
	int cont=0, create_socket, new_socket, addrlen, fd;

	int main(int argc, char **argv)
	{
		char fname[256];
		int bufsize=1024,n;
		buffer=malloc(bufsize);
		struct sockaddr_in address;
	if ((create_socket=socket (AF_INET, SOCK_STREAM, 0));
	printf ("the socket was created");
		address.sin_family=AF_INET;
		address.sin_addr.s_addr=INADDR_ANY;
		address.sin_port=htons(7000);
	}
