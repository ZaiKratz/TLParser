#include "../Public/PageBlockParagraph.h"


//begin namespace block
namespace COMMON
{

PageBlockParagraph::PageBlockParagraph()
{
	this->_ConstructorID = 1182402406;
}

PageBlockParagraph::PageBlockParagraph(TLBaseObject*  text)
{
	this->_ConstructorID = 1182402406;
	this->text = text;
}
void PageBlockParagraph::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockParagraph::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockParagraph::~PageBlockParagraph()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
