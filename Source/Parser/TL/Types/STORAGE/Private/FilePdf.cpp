#include "../Public/FilePdf.h"


//begin namespace block
namespace STORAGE
{

FilePdf::FilePdf()
{
	this->_ConstructorID = -1373745011;
}
void FilePdf::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FilePdf::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FilePdf::~FilePdf()
{

}
}//end namespace block