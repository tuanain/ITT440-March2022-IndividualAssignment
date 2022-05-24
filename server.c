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
