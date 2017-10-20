#include "../Public/DocumentAttributeHasStickers.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeHasStickers::DocumentAttributeHasStickers()
{
	this->_ConstructorID = -1744710921;
}
void DocumentAttributeHasStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DocumentAttributeHasStickers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
DocumentAttributeHasStickers::~DocumentAttributeHasStickers()
{
}
}//end namespace block
