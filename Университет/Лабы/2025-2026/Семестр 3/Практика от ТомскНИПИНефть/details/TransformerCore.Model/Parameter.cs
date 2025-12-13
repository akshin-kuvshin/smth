// author: Danila "akshin_" Axyonov

namespace TransformerCore.Model
{
    /// <summary>
    /// Параметр детали.
    /// </summary>
    /// <typeparam name="T">Тип параметра.</typeparam>
    public class Parameter<T>
    {
        /// <summary>
        /// Экземплярный, шаблонный конструктор класса параметра.
        /// </summary>
        /// <param name="initMinValue">Исходное минимальное значение параматра.</param>
        /// <param name="initValue">Исходное значение параметра.</param>
        /// <param name="initMaxValue">Исходное максимальное значение параматра.</param>
        public Parameter(T initMinValue, T initValue, T initMaxValue)
        {
            MinValue = initMinValue;
            Value = initValue;
            MaxValue = initMaxValue;
        }

        /// <summary>
        /// Минимальное значение параметра.
        /// </summary>
        public T MinValue { get; set; }

        /// <summary>
        /// Текущее значение параметра.
        /// </summary>
        public T Value { get; set; }

        /// <summary>
        /// Максимальное значение параметра.
        /// </summary>
        public T MaxValue { get; set; }
    }
}
