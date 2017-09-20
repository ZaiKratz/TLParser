#include "../Public/SavedGifsNotModified.h"


//begin namespace block
namespace MESSAGES
{

SavedGifsNotModified::SavedGifsNotModified()
{
	this->_ConstructorID = -1571028248;
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
}
SavedGifsNotModified::~SavedGifsNotModified()
{

}
}//end namespace block
