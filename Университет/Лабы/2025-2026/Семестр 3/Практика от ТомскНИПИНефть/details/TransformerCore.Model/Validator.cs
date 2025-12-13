// author: Danila "akshin_" Axyonov

namespace TransformerCore.Model
{
    /// <summary>
    /// Валидатор значения для параметра.
    /// </summary>
    public static class Validator
    {
        /// <summary>
        /// Валидация значения для параметра.
        /// </summary>
        /// <typeparam name="T">Тип параметра; должен реализовывать типизированный интерфейс IComparable.</typeparam>
        /// <param name="parameter">Параметр, для которого проверяется значение.</param>
        /// <param name="value">Проверяемое значение.</param>
        /// <returns>true => проверка пройдена успешно | false => проверка не пройдена.</returns>
        public static bool ValidateParameter<T>(Parameter<T> parameter, T value) where T : IComparable<T>
        {
            return (value.CompareTo(parameter.MinValue) >= 0) && (value.CompareTo(parameter.MaxValue) <= 0);
        }
    }
}
