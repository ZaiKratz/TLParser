#include "../Public/FilePng.h"


//begin namespace block
namespace STORAGE
{

FilePng::FilePng()
{
	this->_ConstructorID = 172975040;
}
void FilePng::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FilePng::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FilePng::~FilePng()
{

}
}//end namespace block
