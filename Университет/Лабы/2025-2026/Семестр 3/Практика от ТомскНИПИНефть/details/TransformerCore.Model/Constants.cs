// author: Danila "akshin_" Axyonov

namespace TransformerCore.Model
{
    /// <summary>
    /// Предельные допустимые значения для параметров сердечника трансформатора.
    /// </summary>
    public static class Constants
    {
        /// <summary>
        /// Минимальная общая длина сердечника трансформатора.
        /// </summary>
        public const double MIN_TOTAL_LENGTH = 16e-3;

        /// <summary>
        /// Максимальная общая длина сердечника трансформатора.
        /// </summary>
        public const double MAX_TOTAL_LENGTH = 65e-3;

        /// <summary>
        /// Минимальная общая высота сердечника трансформатора.
        /// </summary>
        public const double MIN_TOTAL_HEIGHT = 8e-3;

        /// <summary>
        /// Максимальная общая высота сердечника трансформатора.
        /// </summary>
        public const double MAX_TOTAL_HEIGHT = 32.5e-3;

        /// <summary>
        /// Минимальная ширина сердечника трансформатора.
        /// </summary>
        public const double MIN_TOTAL_WIDTH = 4e-3;

        /// <summary>
        /// Максимальная ширина сердечника трансформатора.
        /// </summary>
        public const double MAX_TOTAL_WIDTH = 28e-3;

        /// <summary>
        /// Минимальная длина срединного зубчика сердечника трансформатора.
        /// </summary>
        public const double MIN_MEDIAN_TOOTH_LENGTH = 4e-3;

        /// <summary>
        /// Максимальная длина срединного зубчика сердечника трансформатора.
        /// </summary>
        public const double MAX_MEDIAN_TOOTH_LENGTH = 20e-3;

        /// <summary>
        /// Минимальная длина бокового зубчика сердечника трансформатора.
        /// </summary>
        public const double MIN_SIDE_TOOTH_LENGTH = 2.8e-3;

        /// <summary>
        /// Максимальная длина бокового зубчика сердечника трансформатора.
        /// </summary>
        public const double MAX_SIDE_TOOTH_LENGTH = 10.5e-3;

        /// <summary>
        /// Минимальная длина шага зубчиков сердечника трансформатора.
        /// </summary>
        public const double MIN_TOOTH_STEP_LENGTH = 3.2e-3;

        /// <summary>
        /// Максимальная длина шага зубчиков сердечника трансформатора.
        /// </summary>
        public const double MAX_TOOTH_STEP_LENGTH = 12e-3;

        /// <summary>
        /// Минимальная высота зубчиков сердечника трансформатора.
        /// </summary>
        public const double MIN_TOOTH_HEIGHT = 5.2e-3;

        /// <summary>
        /// Максимальная высота зубчиков сердечника трансформатора.
        /// </summary>
        public const double MAX_TOOTH_HEIGHT = 22e-3;
    }
}
