#include "../Public/TextEmpty.h"


//begin namespace block
namespace COMMON
{

TextEmpty::TextEmpty()
{
	this->_ConstructorID = -599948721;
}
void TextEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TextEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
TextEmpty::~TextEmpty()
{

}
}//end namespace block
