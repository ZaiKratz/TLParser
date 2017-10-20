#include "../Public/SavedGifsNotModified.h"


//begin namespace block
namespace MESSAGES
{

SavedGifsNotModified::SavedGifsNotModified()
{
	this->_ConstructorID = -402498398;
}
void SavedGifsNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SavedGifsNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SavedGifsNotModified::~SavedGifsNotModified()
{
}
}//end namespace block
