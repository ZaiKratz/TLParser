#include "../Public/PhotoSizeEmpty.h"


//begin namespace block
namespace COMMON
{

PhotoSizeEmpty::PhotoSizeEmpty()
{
	this->_ConstructorID = 64;
}

PhotoSizeEmpty::PhotoSizeEmpty(FString type)
{
	this->_ConstructorID = 64;
	this->type = type;
}
void PhotoSizeEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->type);
}


void PhotoSizeEmpty::OnResponce(BinaryReader& Reader)
{
	type = Reader.TGReadString();
}
PhotoSizeEmpty::~PhotoSizeEmpty()
{

}
}//end namespace block
