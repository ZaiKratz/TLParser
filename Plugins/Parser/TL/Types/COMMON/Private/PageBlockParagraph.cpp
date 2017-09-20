#include "../Public/PageBlockParagraph.h"


//begin namespace block
namespace COMMON
{

PageBlockParagraph::PageBlockParagraph()
{
	this->_ConstructorID = 1711766086;
}

PageBlockParagraph::PageBlockParagraph(PRIVATE::RichText* text)
{
	this->_ConstructorID = 1711766086;
	this->text = text;
}
void PageBlockParagraph::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockParagraph::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockParagraph::~PageBlockParagraph()
{

}
}//end namespace block
