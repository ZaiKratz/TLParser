#include "../Public/PageBlockHeader.h"


//begin namespace block
namespace COMMON
{

PageBlockHeader::PageBlockHeader()
{
	this->_ConstructorID = -1076861716;
}

PageBlockHeader::PageBlockHeader(PRIVATE::RichText*  text)
{
	this->_ConstructorID = -1076861716;
	this->text = text;
}
void PageBlockHeader::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockHeader::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockHeader::~PageBlockHeader()
{

}
}//end namespace block
