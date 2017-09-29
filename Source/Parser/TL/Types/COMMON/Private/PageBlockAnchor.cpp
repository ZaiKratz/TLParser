#include "../Public/PageBlockAnchor.h"


//begin namespace block
namespace COMMON
{

PageBlockAnchor::PageBlockAnchor()
{
	this->_ConstructorID = -837994576;
}

PageBlockAnchor::PageBlockAnchor(FString name)
{
	this->_ConstructorID = -837994576;
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
	this->_Responded = true;
}
PageBlockAnchor::~PageBlockAnchor()
{

}
}//end namespace block
