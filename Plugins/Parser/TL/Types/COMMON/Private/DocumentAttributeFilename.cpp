#include "../Public/DocumentAttributeFilename.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeFilename::DocumentAttributeFilename()
{
	this->_ConstructorID = 1744853269;
}

DocumentAttributeFilename::DocumentAttributeFilename(FString file_name)
{
	this->_ConstructorID = 1744853269;
	this->file_name = file_name;
}
void DocumentAttributeFilename::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->file_name);
}


void DocumentAttributeFilename::OnResponce(BinaryReader& Reader)
{
	file_name = Reader.TGReadString();
}
DocumentAttributeFilename::~DocumentAttributeFilename()
{

}
}//end namespace block
