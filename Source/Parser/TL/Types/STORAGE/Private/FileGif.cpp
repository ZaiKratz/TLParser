#include "../Public/FileGif.h"


//begin namespace block
namespace STORAGE
{

FileGif::FileGif()
{
	this->_ConstructorID = -891180321;
}
void FileGif::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FileGif::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FileGif::~FileGif()
{
}
}//end namespace block
