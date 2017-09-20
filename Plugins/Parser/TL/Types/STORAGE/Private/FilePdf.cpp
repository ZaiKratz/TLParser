#include "../Public/FilePdf.h"


//begin namespace block
namespace STORAGE
{

FilePdf::FilePdf()
{
	this->_ConstructorID = -1924129106;
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
}
FilePdf::~FilePdf()
{

}
}//end namespace block
