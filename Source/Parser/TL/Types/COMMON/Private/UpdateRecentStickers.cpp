#include "../Public/UpdateRecentStickers.h"


//begin namespace block
namespace COMMON
{

UpdateRecentStickers::UpdateRecentStickers()
{
	this->_ConstructorID = -1706939360;
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
	this->_Responded = true;
}
UpdateRecentStickers::~UpdateRecentStickers()
{
}
}//end namespace block
