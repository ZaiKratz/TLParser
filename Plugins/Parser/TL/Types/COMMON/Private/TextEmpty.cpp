#include "../Public/TextEmpty.h"


//begin namespace block
namespace COMMON
{

TextEmpty::TextEmpty()
{
	this->_ConstructorID = 1333935580;
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
}
TextEmpty::~TextEmpty()
{

}
}//end namespace block
