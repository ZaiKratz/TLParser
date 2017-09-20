#include "../Public/PageBlockAnchor.h"


//begin namespace block
namespace COMMON
{

PageBlockAnchor::PageBlockAnchor()
{
	this->_ConstructorID = -1338569266;
}

PageBlockAnchor::PageBlockAnchor(FString name)
{
	this->_ConstructorID = -1338569266;
	this->name = name;
}
void PageBlockAnchor::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->name);
}


void PageBlockAnchor::OnResponce(BinaryReader& Reader)
{
	name = Reader.TGReadString();
}
PageBlockAnchor::~PageBlockAnchor()
{

}
}//end namespace block
