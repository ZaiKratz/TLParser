#include "../Public/PageBlockHeader.h"


//begin namespace block
namespace COMMON
{

PageBlockHeader::PageBlockHeader()
{
	this->_ConstructorID = -1076861716;
}

PageBlockHeader::PageBlockHeader(TLBaseObject*  text)
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
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockHeader::~PageBlockHeader()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
