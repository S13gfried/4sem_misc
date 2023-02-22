#include <iostream>
#include <string>

class Pupil
{
    private:
        std::string firstname;
        std::string lastname;

        int grade_math;
        int grade_phys;
        int grade_rusl;

        float mean;

        void updateMean()
        {
            mean = (float)(grade_math + grade_phys + grade_rusl)/3.0f;
        }

    public:
        Pupil(std::string firstname_new, std::string lastname_new)
        {
            firstname = firstname_new;
            lastname = lastname_new;
        }
        void GradePhys(int grade)
        { grade_phys = grade; }
        void GradeMath(int grade)
        { grade_math = grade; }
        void GradeRusl(int grade)
        { grade_rusl = grade; }

        float getMean()
        {
            updateMean();
            return mean;
        }
};

int main()
{
    Pupil newpupil = Pupil("aaaa", "bbb");
    int gradeBuffer;

    std::cin >> gradeBuffer;
    newpupil.GradePhys(gradeBuffer);
    std::cin >> gradeBuffer;
    newpupil.GradeMath(gradeBuffer);
    std::cin >> gradeBuffer;
    newpupil.GradeRusl(gradeBuffer);

    std::cout << newpupil.getMean();

    return 0;
}