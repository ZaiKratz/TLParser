#include "../Public/DocumentAttributeHasStickers.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeHasStickers::DocumentAttributeHasStickers()
{
	this->_ConstructorID = -137231976;
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
}
DocumentAttributeHasStickers::~DocumentAttributeHasStickers()
{

}
}//end namespace block
