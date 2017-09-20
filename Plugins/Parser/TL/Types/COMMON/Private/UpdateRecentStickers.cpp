#include "../Public/UpdateRecentStickers.h"


//begin namespace block
namespace COMMON
{

UpdateRecentStickers::UpdateRecentStickers()
{
	this->_ConstructorID = 539771546;
}
void UpdateRecentStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateRecentStickers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UpdateRecentStickers::~UpdateRecentStickers()
{

}
}//end namespace block
